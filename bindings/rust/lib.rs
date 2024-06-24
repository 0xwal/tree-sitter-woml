use std::collections::HashMap;

use tree_sitter::{
	Language,
	Node,
};

extern "C" {
	fn tree_sitter_woml() -> Language;
}

pub fn language() -> Language {
	unsafe { tree_sitter_woml() }
}

#[derive(Debug, PartialEq, Eq)]
pub struct WomlValue {
	pub value: String,
	pub tags: Vec<String>,
	pub labels: Vec<String>,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Entry {
	Text(String, WomlValue),
	List(String, Vec<WomlValue>),
	Object(String, HashMap<String, WomlValue>),
}

pub type Entries = Vec<Entry>;

pub struct Woml {
	pub root_text: Option<WomlValue>,
	pub entries: Option<Entries>,
}

fn extract_root_text(source: impl AsRef<[u8]>, node: Node) -> Option<WomlValue> {
	let root_text_node = node.child_by_field_name("rootText")?;

	let text = root_text_node
		.child(0)?
		.utf8_text(source.as_ref())
		.unwrap()
		.to_string();

	let mut walking = root_text_node.walk();

	let tags = root_text_node
		.children_by_field_name("tag", &mut walking)
		.map(|n| n.utf8_text(source.as_ref()).unwrap().to_string())
		.collect::<Vec<String>>();

	let labels = root_text_node
		.children_by_field_name("label", &mut walking)
		.map(|n| n.utf8_text(source.as_ref()).unwrap().to_string())
		.collect::<Vec<String>>();

	Some(WomlValue {
		value: text,
		tags,
		labels,
	})
}

fn extract_entries(source: impl AsRef<[u8]>, node: Node) -> Option<Entries> {
	let entries_node = node.child_by_field_name("entries")?;

	let mut walking = entries_node.walk();
	//
	let entries = entries_node.children(&mut walking);
	//
	let mut out = vec![];
	for entry in entries {
		let name = entry.kind();
		let header = entry
			.child_by_field_name("header")
			.expect("could not find header")
			.child_by_field_name("identifier")
			.expect("could not find identifier");

		let header = header.utf8_text(source.as_ref()).unwrap();

		if name == "entryText" {
			let content = entry
				.child_by_field_name("content")
				.expect("text has no content");

			let text = content
				.child_by_field_name("text")
				.expect("content has no text");

			let text = text
				.utf8_text(source.as_ref())
				.expect("could not get the text")
				.trim();

			let mut walking = content.walk();

			let tags = content
				.children_by_field_name("tag", &mut walking)
				.map(|t| t.utf8_text(source.as_ref()).unwrap().to_string())
				.collect::<Vec<String>>();

			let labels = content
				.children_by_field_name("label", &mut walking)
				.map(|t| t.utf8_text(source.as_ref()).unwrap().to_string())
				.collect::<Vec<String>>();

			out.push(Entry::Text(
				header.to_owned(),
				WomlValue {
					value: text.to_owned(),
					tags,
					labels,
				},
			));
			continue;
		}

		if name == "entryList" {
			let mut walking = entry.walk();
			let list_items = entry.children_by_field_name("listItem", &mut walking);

			let mut values = vec![];

			for list_item in list_items {
				let item = list_item
					.child_by_field_name("item")
					.expect("item not found");

				let line = item
					.child_by_field_name("line")
					.expect("line not found")
					.utf8_text(source.as_ref())
					.unwrap()
					.trim()
					.to_string();

				let mut walking = item.walk();

				let tags = item
					.children_by_field_name("tag", &mut walking)
					.map(|t| t.utf8_text(source.as_ref()).unwrap().to_string())
					.collect::<Vec<String>>();

				let labels = item
					.children_by_field_name("label", &mut walking)
					.map(|t| t.utf8_text(source.as_ref()).unwrap().to_string())
					.collect::<Vec<String>>();

				values.push(WomlValue {
					value: line,
					tags,
					labels,
				})
			}

			out.push(Entry::List(header.to_owned(), values));
			continue;
		}

		if name == "entryObject" {
			let mut map: HashMap<String, WomlValue> = HashMap::new();
			let header = entry
				.child_by_field_name("header")
				.expect("no header found");
			let header = header
				.child_by_field_name("identifier")
				.expect("header has no identifier");
			let header = header
				.utf8_text(source.as_ref())
				.expect("cannot get the header text");

			let mut walking = entry.walk();
			let pairs = entry.children_by_field_name("pair", &mut walking);

			for pair in pairs {
				let key = pair.child_by_field_name("key").expect("pair has no key");
				let key = key.utf8_text(source.as_ref()).expect("pair has not text");

				let value = pair
					.child_by_field_name("value")
					.expect("pair has no value");

				let line = value
					.child_by_field_name("line")
					.expect("pair value has no line");

				let line = line
					.utf8_text(source.as_ref())
					.expect("line has no text")
					.trim();

				let mut walking = value.walk();
				let tags = value
					.children_by_field_name("tag", &mut walking)
					.map(|n| n.utf8_text(source.as_ref()).unwrap().to_string())
					.collect::<Vec<String>>();

				let labels = value
					.children_by_field_name("label", &mut walking)
					.map(|n| n.utf8_text(source.as_ref()).unwrap().to_string())
					.collect::<Vec<String>>();

				map.insert(
					key.to_string(),
					WomlValue {
						value: line.to_string(),
						tags,
						labels,
					},
				);
			}

			out.push(Entry::Object(header.to_owned(), map));
			continue;
		}
	}

	Some(out)
}

pub fn parse(source: impl AsRef<[u8]>) -> Option<Woml> {
	let mut parser = tree_sitter::Parser::new();
	parser.set_language(&language()).ok()?;

	let tree = parser.parse(&source, None)?;

	let root_text = extract_root_text(&source, tree.root_node());
	let entries = extract_entries(&source, tree.root_node());
	Some(Woml {
		root_text,
		entries,
	})
}

#[allow(dead_code)]
const CODE: &str = r#"
this is a root text
with multiple lines
#tag @label

[listHeader]
- item 1 #tag1 #tag2 @label1
- item 2 @label1 @label2 #tag1
- item 3

[objectHeader]
key1: this is my value 1 #tag1 @label1
key2: this is my value 2 @label1 #tag1 @label2
key3: this is my value without meta

[textHeader]
this is my multiline text
that can have tags and labels
at the end #tag1
@label1

"#;

#[cfg(test)]
mod tests {

	use super::*;

	#[test]
	fn can_parse_root_text() {
		let woml = parse(CODE);

		let woml = woml.expect("woml is none");

		let root_text = woml.root_text.expect("root text is None");

		let value = root_text.value;

		assert_eq!(
			value,
			r#"this is a root text
with multiple lines"#
		);

		assert_eq!(root_text.tags, vec!["#tag"]);
		assert_eq!(root_text.labels, vec!["@label"]);
	}

	#[test]
	fn can_parse_entries() {
		let woml = parse(CODE);

		let woml = woml.expect("woml is none");

		let entries = woml.entries.expect("entries is None");

		assert_eq!(entries.len(), 3);

		match &entries[0] {
			Entry::List(header, items) => {
				assert_eq!(*header, "listHeader".to_string());

				assert_eq!(items[0].value, "item 1");
				assert_eq!(
					items[0].tags,
					vec!["#tag1".to_string(), "#tag2".to_string()]
				);
				assert_eq!(items[0].labels, vec!["@label1".to_string()]);

				assert_eq!(items[1].value, "item 2");
				assert_eq!(items[1].tags, vec!["#tag1".to_string()]);
				assert_eq!(
					items[1].labels,
					vec!["@label1".to_string(), "@label2".to_string()]
				);

				assert_eq!(items[2].value, "item 3");
				assert_eq!(items[2].tags, Vec::<String>::new());
				assert_eq!(items[2].labels, vec![] as Vec<String>);
			}
			_ => unreachable!(),
		}

		match &entries[1] {
			Entry::Object(header, map) => {
				assert_eq!(*header, "objectHeader".to_string());

				assert_eq!(map.get("key1").unwrap().value, "this is my value 1");
				assert_eq!(map.get("key1").unwrap().tags, vec!["#tag1".to_string()]);
				assert_eq!(map.get("key1").unwrap().labels, vec!["@label1".to_string()]);

				assert_eq!(map.get("key2").unwrap().value, "this is my value 2");
				assert_eq!(map.get("key2").unwrap().tags, vec!["#tag1".to_string()]);
				assert_eq!(
					map.get("key2").unwrap().labels,
					vec!["@label1".to_string(), "@label2".to_string()]
				);

				assert_eq!(
					map.get("key3").unwrap().value,
					"this is my value without meta"
				);
				assert_eq!(map.get("key3").unwrap().tags, vec![] as Vec<String>);
				assert_eq!(map.get("key3").unwrap().labels, vec![] as Vec<String>);
			}
			_ => unreachable!(),
		}

		match &entries[2] {
			Entry::Text(header, text) => {
				assert_eq!(*header, "textHeader".to_string());

				assert_eq!(
					text.value,
					"this is my multiline text
that can have tags and labels
at the end"
				);

				assert_eq!(text.tags, vec!["#tag1"]);
				assert_eq!(text.labels, vec!["@label1"]);
			}
			_ => unreachable!(),
		}
	}
}

#[cfg(test)]
mod ast_tests {
	// use tree_sitter::{
	// 	Node,
	// 	Tree,
	// };
	//
	// use crate::CODE;
	//
	// fn get_ast() -> Tree {
	// 	let mut parser = tree_sitter::Parser::new();
	// 	parser
	// 		.set_language(&super::language())
	// 		.expect("Error loading Woml grammar");
	//
	// 	let tree = parser.parse(CODE, None);
	// 	tree.unwrap()
	// }
	//
	// #[test]
	// fn test_can_get_root_text() {
	// 	let tree = get_ast();
	// 	let root_text = tree.root_node().child_by_field_name("rootText");
	// 	assert!(root_text.is_some());
	// }
	//
	// #[test]
	// fn test_can_get_entries() {
	// 	let tree = get_ast();
	// 	let entries = tree
	// 		.root_node()
	// 		.child_by_field_name("entries")
	// 		.expect("entries child not found");
	// 	let mut walk = entries.walk();
	// 	let entries = entries.children(&mut walk);
	//
	// 	assert_eq!(entries.collect::<Vec<Node>>().len(), 3);
	// }
	//
	// #[test]
	// fn test_can_get_all_list_items() {
	// 	let tree = get_ast();
	// 	let entries = tree
	// 		.root_node()
	// 		.child_by_field_name("entries")
	// 		.expect("entries child not found");
	//
	// 	let mut walk = entries.walk();
	//
	// 	let entry_list = entries
	// 		.child_by_field_name("entry")
	// 		.expect("could not find entryList");
	//
	// 	let list_items = entry_list.children_by_field_name("listItem", &mut walk);
	//
	// 	assert_eq!(list_items.collect::<Vec<Node>>().len(), 3);
	// }
	//
	// #[test]
	// fn test_can_get_all_object_pairs() {
	// 	let tree = get_ast();
	// 	let entries = tree
	// 		.root_node()
	// 		.child_by_field_name("entries")
	// 		.expect("entries child not found");
	//
	// 	let mut walk = entries.walk();
	//
	// 	let entry_object = entries
	// 		.child_by_field_name("entry")
	// 		.expect("could not find entry");
	//
	// 	let pairs = entry_object.children_by_field_name("pair", &mut walk);
	//
	// 	assert_eq!(pairs.collect::<Vec<Node>>().len(), 3);
	// }
	//
	// #[test]
	// fn test_can_get_object_pair() {
	// 	let tree = get_ast();
	// 	let entries = tree
	// 		.root_node()
	// 		.child_by_field_name("entries")
	// 		.expect("entries child not found");
	//
	// 	let mut walk = entries.walk();
	//
	// 	let entry_object = entries
	// 		.child_by_field_name("entryObject")
	// 		.expect("could not find entryObject");
	//
	// 	let pairs = entry_object.children_by_field_name("pair", &mut walk);
	//
	// 	let mut expected = vec![
	// 		("key1", "this is my value 1", 1, 1),
	// 		("key2", "this is my value 2", 1, 2),
	// 		("key3", "this is my value without meta", 0, 0),
	// 	];
	//
	// 	for pair in pairs {
	// 		let key = pair
	// 			.child_by_field_name("key")
	// 			.expect("could not find the key for pair");
	// 		let value = pair
	// 			.child_by_field_name("value")
	// 			.expect("could not find the value for pair");
	//
	// 		let line = value.child_by_field_name("line").unwrap();
	//
	// 		let mut walk = value.walk();
	// 		let tags = {
	// 			let tags = value.children_by_field_name("tag", &mut walk);
	// 			tags.collect::<Vec<Node>>()
	// 		};
	//
	// 		let labels = {
	// 			let labels = value.children_by_field_name("label", &mut walk);
	// 			labels.collect::<Vec<Node>>()
	// 		};
	//
	// 		let expected = expected.remove(0);
	//
	// 		assert_eq!(key.utf8_text(CODE.as_bytes()).unwrap().trim(), expected.0);
	// 		assert_eq!(line.utf8_text(CODE.as_bytes()).unwrap().trim(), expected.1);
	//
	// 		assert_eq!(tags.len(), expected.2);
	// 		assert_eq!(labels.len(), expected.3);
	// 	}
	// }
}
