//! This crate provides Woml language support for the [tree-sitter][] parsing library.
use tree_sitter::Language;

extern "C" {
	fn tree_sitter_woml() -> Language;
}

/// Get the tree-sitter [Language][] for this grammar.
///
/// [Language]: https://docs.rs/tree-sitter/*/tree_sitter/struct.Language.html
pub fn language() -> Language {
	unsafe { tree_sitter_woml() }
}

/// The content of the [`node-types.json`][] file for this grammar.
///
/// [`node-types.json`]: https://tree-sitter.github.io/tree-sitter/using-parsers#static-node-types
pub const NODE_TYPES: &str = include_str!("../../src/node-types.json");

// Uncomment these to include any queries that this grammar contains

// pub const HIGHLIGHTS_QUERY: &str = include_str!("../../queries/highlights.scm");
// pub const INJECTIONS_QUERY: &str = include_str!("../../queries/injections.scm");
// pub const LOCALS_QUERY: &str = include_str!("../../queries/locals.scm");
// pub const TAGS_QUERY: &str = include_str!("../../queries/tags.scm");

// pub const CODE: &str = include_str!("../../test/scratch.txt");

pub const CODE: &str = r#"
this is a root text
with multiple lines

[listHeader]
- item 1 #tag1 #tag2 @label1
- item 2 @lable1 @label2 #tag1
- item 3

[objectHeader]
key1: this is my value 1 #tag1 @label1
key2: this is my value 2 @label1 #tag1 @label2
key3: this is my value without meta

[textHeader]
this is my multiline text
that can have tags and labels
at the end #tag1
@label2

"#;

#[cfg(test)]
mod tests {

	use tree_sitter::{
		Node,
		Tree,
	};

	use crate::CODE;

	fn get_ast() -> Tree {
		let mut parser = tree_sitter::Parser::new();
		parser
			.set_language(&super::language())
			.expect("Error loading Woml grammar");

		let tree = parser.parse(CODE, None);
		tree.unwrap()
	}

	#[test]
	fn test_can_get_root_text() {
		let tree = get_ast();
		let root_text = tree.root_node().child_by_field_name("rootText");
		assert!(root_text.is_some());
	}

	#[test]
	fn test_can_get_entries() {
		let tree = get_ast();
		let entries = tree
			.root_node()
			.child_by_field_name("entries")
			.expect("entries child not found");
		let mut walk = entries.walk();
		let entries = entries.children(&mut walk);

		assert_eq!(entries.collect::<Vec<Node>>().len(), 3);
	}

	#[test]
	fn test_can_get_all_list_items() {
		let tree = get_ast();
		let entries = tree
			.root_node()
			.child_by_field_name("entries")
			.expect("entries child not found");

		let mut walk = entries.walk();

		let entry_list = entries
			.child_by_field_name("entryList")
			.expect("could not find entryList");

		let list_items = entry_list.children_by_field_name("listItem", &mut walk);

		assert_eq!(list_items.collect::<Vec<Node>>().len(), 3);
	}

	#[test]
	fn test_can_get_all_object_pairs() {
		let tree = get_ast();
		let entries = tree
			.root_node()
			.child_by_field_name("entries")
			.expect("entries child not found");

		let mut walk = entries.walk();

		let entry_object = entries
			.child_by_field_name("entryObject")
			.expect("could not find entryObject");

		let pairs = entry_object.children_by_field_name("pair", &mut walk);

		assert_eq!(pairs.collect::<Vec<Node>>().len(), 3);
	}

	#[test]
	fn test_can_get_object_pair() {
		let tree = get_ast();
		let entries = tree
			.root_node()
			.child_by_field_name("entries")
			.expect("entries child not found");

		let mut walk = entries.walk();

		let entry_object = entries
			.child_by_field_name("entryObject")
			.expect("could not find entryObject");

		let pairs = entry_object.children_by_field_name("pair", &mut walk);

		let mut expected = vec![
			("key1", "this is my value 1", 1, 1),
			("key2", "this is my value 2", 1, 2),
			("key3", "this is my value without meta", 0, 0),
		];

		for pair in pairs {
			let key = pair
				.child_by_field_name("key")
				.expect("could not find the key for pair");
			let value = pair
				.child_by_field_name("value")
				.expect("could not find the value for pair");

			let line = value.child_by_field_name("line").unwrap();

			let mut walk = value.walk();
			let tags = {
				let tags = value.children_by_field_name("tag", &mut walk);
				tags.collect::<Vec<Node>>()
			};

			let labels = {
				let labels = value.children_by_field_name("label", &mut walk);
				labels.collect::<Vec<Node>>()
			};

			let expected = expected.remove(0);

			assert_eq!(key.utf8_text(CODE.as_bytes()).unwrap().trim(), expected.0);
			assert_eq!(line.utf8_text(CODE.as_bytes()).unwrap().trim(), expected.1);

			assert_eq!(tags.len(), expected.2);
			assert_eq!(labels.len(), expected.3);
		}
	}
}
