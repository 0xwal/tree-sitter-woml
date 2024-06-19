package tree_sitter_woml_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-woml"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_woml.Language())
	if language == nil {
		t.Errorf("Error loading Woml grammar")
	}
}
