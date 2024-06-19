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

pub const CODE: &str = include_str!("../../demo.txt");
#[cfg(test)]
mod tests {
	use tree_sitter::{
		Node,
		Query,
		QueryCursor,
	};

	use crate::CODE;

	#[test]
	fn test_can_load_grammar() {
		let mut parser = tree_sitter::Parser::new();
		parser
			.set_language(&super::language())
			.expect("Error loading Woml grammar");

		let tree = parser.parse(CODE, None);
		let tree = tree.unwrap();
		let root_node = tree.root_node();

		let query = Query::new(
			&parser.language().unwrap(),
			r#"
(entryList
    (value
        (meta (tag) @tag)
    )
)
"#,
		)
		.unwrap();

		let mut query_cur = QueryCursor::new();
		let captures = query_cur.matches(&query, root_node, CODE.as_bytes());

		for capture in captures {
			for capture in capture.captures {
				let node = capture.node;
				let text = &node.utf8_text(CODE.as_bytes());
				println!("Captured: {:?}, Text: {:?}", capture.index, text);
			}
		}
	}
}
