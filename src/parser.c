#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 40
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 27
#define ALIAS_COUNT 5
#define TOKEN_COUNT 9
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 12
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 27

enum ts_symbol_identifiers {
  anon_sym_COLON = 1,
  anon_sym_LBRACK = 2,
  anon_sym_RBRACK = 3,
  anon_sym_AT = 4,
  anon_sym_POUND = 5,
  sym_identifier = 6,
  sym__text = 7,
  sym_minus = 8,
  sym_doc = 9,
  sym_entries = 10,
  sym_entryObject = 11,
  sym_pair = 12,
  sym_entryText = 13,
  sym_entryList = 14,
  sym_listItem = 15,
  sym_header = 16,
  sym_text = 17,
  sym_line = 18,
  sym__meta = 19,
  sym_label = 20,
  sym_tag = 21,
  aux_sym_entries_repeat1 = 22,
  aux_sym_entryObject_repeat1 = 23,
  aux_sym_entryList_repeat1 = 24,
  aux_sym_text_repeat1 = 25,
  aux_sym_text_repeat2 = 26,
  alias_sym_content = 27,
  anon_alias_sym_labelIdentifier = 28,
  anon_alias_sym_tagIdentifier = 29,
  alias_sym_text = 30,
  alias_sym_value = 31,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_COLON] = ":",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_AT] = "@",
  [anon_sym_POUND] = "#",
  [sym_identifier] = "identifier",
  [sym__text] = "_text",
  [sym_minus] = "minus",
  [sym_doc] = "doc",
  [sym_entries] = "entries",
  [sym_entryObject] = "entry",
  [sym_pair] = "pair",
  [sym_entryText] = "entryText",
  [sym_entryList] = "entry",
  [sym_listItem] = "listItem",
  [sym_header] = "header",
  [sym_text] = "rootText",
  [sym_line] = "line",
  [sym__meta] = "_meta",
  [sym_label] = "label",
  [sym_tag] = "tag",
  [aux_sym_entries_repeat1] = "entries_repeat1",
  [aux_sym_entryObject_repeat1] = "entryObject_repeat1",
  [aux_sym_entryList_repeat1] = "entryList_repeat1",
  [aux_sym_text_repeat1] = "text_repeat1",
  [aux_sym_text_repeat2] = "text_repeat2",
  [alias_sym_content] = "content",
  [anon_alias_sym_labelIdentifier] = "labelIdentifier",
  [anon_alias_sym_tagIdentifier] = "tagIdentifier",
  [alias_sym_text] = "text",
  [alias_sym_value] = "value",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_POUND] = anon_sym_POUND,
  [sym_identifier] = sym_identifier,
  [sym__text] = sym__text,
  [sym_minus] = sym_minus,
  [sym_doc] = sym_doc,
  [sym_entries] = sym_entries,
  [sym_entryObject] = sym_entryObject,
  [sym_pair] = sym_pair,
  [sym_entryText] = sym_entryText,
  [sym_entryList] = sym_entryObject,
  [sym_listItem] = sym_listItem,
  [sym_header] = sym_header,
  [sym_text] = sym_text,
  [sym_line] = sym_line,
  [sym__meta] = sym__meta,
  [sym_label] = sym_label,
  [sym_tag] = sym_tag,
  [aux_sym_entries_repeat1] = aux_sym_entries_repeat1,
  [aux_sym_entryObject_repeat1] = aux_sym_entryObject_repeat1,
  [aux_sym_entryList_repeat1] = aux_sym_entryList_repeat1,
  [aux_sym_text_repeat1] = aux_sym_text_repeat1,
  [aux_sym_text_repeat2] = aux_sym_text_repeat2,
  [alias_sym_content] = alias_sym_content,
  [anon_alias_sym_labelIdentifier] = anon_alias_sym_labelIdentifier,
  [anon_alias_sym_tagIdentifier] = anon_alias_sym_tagIdentifier,
  [alias_sym_text] = alias_sym_text,
  [alias_sym_value] = alias_sym_value,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym__text] = {
    .visible = false,
    .named = true,
  },
  [sym_minus] = {
    .visible = true,
    .named = true,
  },
  [sym_doc] = {
    .visible = true,
    .named = true,
  },
  [sym_entries] = {
    .visible = true,
    .named = true,
  },
  [sym_entryObject] = {
    .visible = true,
    .named = true,
  },
  [sym_pair] = {
    .visible = true,
    .named = true,
  },
  [sym_entryText] = {
    .visible = true,
    .named = true,
  },
  [sym_entryList] = {
    .visible = true,
    .named = true,
  },
  [sym_listItem] = {
    .visible = true,
    .named = true,
  },
  [sym_header] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_line] = {
    .visible = true,
    .named = true,
  },
  [sym__meta] = {
    .visible = false,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_entries_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entryObject_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_entryList_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_text_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_text_repeat2] = {
    .visible = false,
    .named = false,
  },
  [alias_sym_content] = {
    .visible = true,
    .named = true,
  },
  [anon_alias_sym_labelIdentifier] = {
    .visible = true,
    .named = false,
  },
  [anon_alias_sym_tagIdentifier] = {
    .visible = true,
    .named = false,
  },
  [alias_sym_text] = {
    .visible = true,
    .named = true,
  },
  [alias_sym_value] = {
    .visible = true,
    .named = true,
  },
};

enum ts_field_identifiers {
  field_entries = 1,
  field_entryList = 2,
  field_entryObject = 3,
  field_item = 4,
  field_key = 5,
  field_label = 6,
  field_line = 7,
  field_listItem = 8,
  field_pair = 9,
  field_rootText = 10,
  field_tag = 11,
  field_value = 12,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_entries] = "entries",
  [field_entryList] = "entryList",
  [field_entryObject] = "entryObject",
  [field_item] = "item",
  [field_key] = "key",
  [field_label] = "label",
  [field_line] = "line",
  [field_listItem] = "listItem",
  [field_pair] = "pair",
  [field_rootText] = "rootText",
  [field_tag] = "tag",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 2},
  [7] = {.index = 6, .length = 1},
  [8] = {.index = 7, .length = 1},
  [10] = {.index = 8, .length = 1},
  [11] = {.index = 9, .length = 1},
  [12] = {.index = 10, .length = 2},
  [13] = {.index = 12, .length = 4},
  [14] = {.index = 16, .length = 2},
  [15] = {.index = 18, .length = 1},
  [16] = {.index = 19, .length = 1},
  [17] = {.index = 20, .length = 2},
  [18] = {.index = 22, .length = 1},
  [19] = {.index = 23, .length = 1},
  [20] = {.index = 24, .length = 2},
  [21] = {.index = 26, .length = 2},
  [24] = {.index = 28, .length = 4},
  [25] = {.index = 32, .length = 2},
  [26] = {.index = 34, .length = 3},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_entries, 0},
  [1] =
    {field_entryObject, 0},
  [2] =
    {field_entryList, 0},
  [3] =
    {field_rootText, 0},
  [4] =
    {field_entryList, 0, .inherited = true},
    {field_entryObject, 0, .inherited = true},
  [6] =
    {field_pair, 0},
  [7] =
    {field_listItem, 0},
  [8] =
    {field_pair, 1, .inherited = true},
  [9] =
    {field_listItem, 1, .inherited = true},
  [10] =
    {field_entries, 1},
    {field_rootText, 0},
  [12] =
    {field_entryList, 0, .inherited = true},
    {field_entryList, 1, .inherited = true},
    {field_entryObject, 0, .inherited = true},
    {field_entryObject, 1, .inherited = true},
  [16] =
    {field_label, 0, .inherited = true},
    {field_tag, 0, .inherited = true},
  [18] =
    {field_label, 0},
  [19] =
    {field_tag, 0},
  [20] =
    {field_label, 1, .inherited = true},
    {field_tag, 1, .inherited = true},
  [22] =
    {field_line, 0},
  [23] =
    {field_item, 1},
  [24] =
    {field_pair, 0, .inherited = true},
    {field_pair, 1, .inherited = true},
  [26] =
    {field_listItem, 0, .inherited = true},
    {field_listItem, 1, .inherited = true},
  [28] =
    {field_label, 0, .inherited = true},
    {field_label, 1, .inherited = true},
    {field_tag, 0, .inherited = true},
    {field_tag, 1, .inherited = true},
  [32] =
    {field_key, 0},
    {field_value, 2},
  [34] =
    {field_label, 1, .inherited = true},
    {field_line, 0},
    {field_tag, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [6] = {
    [0] = alias_sym_text,
  },
  [9] = {
    [1] = alias_sym_content,
  },
  [17] = {
    [0] = alias_sym_text,
  },
  [18] = {
    [0] = alias_sym_text,
  },
  [19] = {
    [1] = alias_sym_value,
  },
  [22] = {
    [1] = anon_alias_sym_labelIdentifier,
  },
  [23] = {
    [1] = anon_alias_sym_tagIdentifier,
  },
  [26] = {
    [0] = alias_sym_text,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  sym_text, 2,
    sym_text,
    alias_sym_content,
  sym_line, 2,
    sym_line,
    alias_sym_value,
  aux_sym_text_repeat1, 2,
    aux_sym_text_repeat1,
    alias_sym_text,
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
};

static TSCharacterRange sym__text_character_set_1[] = {
  {' ', '"'}, {'\'', ')'}, {',', '.'}, {'0', '9'}, {'?', '?'}, {'A', '['}, {']', ']'}, {'_', '_'},
  {'a', '{'}, {'}', '}'},
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(4);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == '@') ADVANCE(8);
      if (lookahead == '[') ADVANCE(6);
      if (lookahead == ']') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(1);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 1:
      if (set_contains(sym__text_character_set_1, 10, lookahead)) ADVANCE(12);
      END_STATE();
    case 2:
      if (eof) ADVANCE(4);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '-') ADVANCE(13);
      if (lookahead == '@') ADVANCE(8);
      if (lookahead == '[') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 3:
      if (eof) ADVANCE(4);
      if (lookahead == '#') ADVANCE(9);
      if (lookahead == '@') ADVANCE(8);
      if (lookahead == '[') ADVANCE(6);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(3);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(1);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(sym_identifier);
      if ((set_contains(sym__text_character_set_1, 10, lookahead)) &&
          (lookahead < '0' || '9' < lookahead) &&
          (lookahead < 'A' || 'Z' < lookahead) &&
          lookahead != '_' &&
          (lookahead < 'a' || 'z' < lookahead)) ADVANCE(12);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(10);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym__text);
      if (set_contains(sym__text_character_set_1, 10, lookahead)) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(sym_minus);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 2},
  [3] = {.lex_state = 2},
  [4] = {.lex_state = 3},
  [5] = {.lex_state = 2},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 2},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 3},
  [21] = {.lex_state = 2},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 3},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 2},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 0},
  [38] = {.lex_state = 0},
  [39] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym__text] = ACTIONS(1),
    [sym_minus] = ACTIONS(1),
  },
  [1] = {
    [sym_doc] = STATE(39),
    [sym_entries] = STATE(38),
    [sym_entryObject] = STATE(31),
    [sym_entryText] = STATE(10),
    [sym_entryList] = STATE(30),
    [sym_header] = STATE(6),
    [sym_text] = STATE(8),
    [aux_sym_entries_repeat1] = STATE(10),
    [aux_sym_text_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(5),
    [sym__text] = ACTIONS(7),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 7,
    ACTIONS(11), 1,
      anon_sym_AT,
    ACTIONS(13), 1,
      anon_sym_POUND,
    STATE(3), 1,
      aux_sym_text_repeat2,
    STATE(14), 1,
      sym_tag,
    STATE(15), 1,
      sym_label,
    STATE(16), 1,
      sym__meta,
    ACTIONS(9), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_identifier,
      sym_minus,
  [25] = 7,
    ACTIONS(17), 1,
      anon_sym_AT,
    ACTIONS(20), 1,
      anon_sym_POUND,
    STATE(3), 1,
      aux_sym_text_repeat2,
    STATE(14), 1,
      sym_tag,
    STATE(15), 1,
      sym_label,
    STATE(16), 1,
      sym__meta,
    ACTIONS(15), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_identifier,
      sym_minus,
  [50] = 9,
    ACTIONS(7), 1,
      sym__text,
    ACTIONS(11), 1,
      anon_sym_AT,
    ACTIONS(13), 1,
      anon_sym_POUND,
    STATE(7), 1,
      aux_sym_text_repeat2,
    STATE(11), 1,
      aux_sym_text_repeat1,
    STATE(14), 1,
      sym_tag,
    STATE(15), 1,
      sym_label,
    STATE(16), 1,
      sym__meta,
    ACTIONS(23), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [79] = 7,
    ACTIONS(11), 1,
      anon_sym_AT,
    ACTIONS(13), 1,
      anon_sym_POUND,
    STATE(2), 1,
      aux_sym_text_repeat2,
    STATE(14), 1,
      sym_tag,
    STATE(15), 1,
      sym_label,
    STATE(16), 1,
      sym__meta,
    ACTIONS(25), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_identifier,
      sym_minus,
  [104] = 9,
    ACTIONS(27), 1,
      sym_identifier,
    ACTIONS(29), 1,
      sym__text,
    ACTIONS(31), 1,
      sym_minus,
    STATE(4), 1,
      aux_sym_text_repeat1,
    STATE(18), 1,
      aux_sym_entryObject_repeat1,
    STATE(19), 1,
      aux_sym_entryList_repeat1,
    STATE(22), 1,
      sym_listItem,
    STATE(23), 1,
      sym_pair,
    STATE(28), 1,
      sym_text,
  [132] = 7,
    ACTIONS(11), 1,
      anon_sym_AT,
    ACTIONS(13), 1,
      anon_sym_POUND,
    STATE(3), 1,
      aux_sym_text_repeat2,
    STATE(14), 1,
      sym_tag,
    STATE(15), 1,
      sym_label,
    STATE(16), 1,
      sym__meta,
    ACTIONS(33), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [155] = 7,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(35), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      sym_header,
    STATE(30), 1,
      sym_entryList,
    STATE(31), 1,
      sym_entryObject,
    STATE(35), 1,
      sym_entries,
    STATE(10), 2,
      sym_entryText,
      aux_sym_entries_repeat1,
  [178] = 6,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      anon_sym_LBRACK,
    STATE(6), 1,
      sym_header,
    STATE(30), 1,
      sym_entryList,
    STATE(31), 1,
      sym_entryObject,
    STATE(9), 2,
      sym_entryText,
      aux_sym_entries_repeat1,
  [198] = 6,
    ACTIONS(5), 1,
      anon_sym_LBRACK,
    ACTIONS(42), 1,
      ts_builtin_sym_end,
    STATE(6), 1,
      sym_header,
    STATE(30), 1,
      sym_entryList,
    STATE(31), 1,
      sym_entryObject,
    STATE(9), 2,
      sym_entryText,
      aux_sym_entries_repeat1,
  [218] = 3,
    ACTIONS(46), 1,
      sym__text,
    STATE(11), 1,
      aux_sym_text_repeat1,
    ACTIONS(44), 4,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
  [231] = 1,
    ACTIONS(49), 6,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym_identifier,
      sym_minus,
  [240] = 1,
    ACTIONS(51), 6,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym_identifier,
      sym_minus,
  [249] = 1,
    ACTIONS(53), 6,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym_identifier,
      sym_minus,
  [258] = 1,
    ACTIONS(55), 6,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym_identifier,
      sym_minus,
  [267] = 1,
    ACTIONS(57), 6,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym_identifier,
      sym_minus,
  [276] = 4,
    ACTIONS(61), 1,
      sym_minus,
    STATE(17), 1,
      aux_sym_entryList_repeat1,
    STATE(22), 1,
      sym_listItem,
    ACTIONS(59), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [290] = 4,
    ACTIONS(66), 1,
      sym_identifier,
    STATE(21), 1,
      aux_sym_entryObject_repeat1,
    STATE(23), 1,
      sym_pair,
    ACTIONS(64), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [304] = 4,
    ACTIONS(31), 1,
      sym_minus,
    STATE(17), 1,
      aux_sym_entryList_repeat1,
    STATE(22), 1,
      sym_listItem,
    ACTIONS(68), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [318] = 1,
    ACTIONS(70), 5,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      anon_sym_AT,
      anon_sym_POUND,
      sym__text,
  [326] = 4,
    ACTIONS(74), 1,
      sym_identifier,
    STATE(21), 1,
      aux_sym_entryObject_repeat1,
    STATE(23), 1,
      sym_pair,
    ACTIONS(72), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [340] = 1,
    ACTIONS(77), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_minus,
  [346] = 1,
    ACTIONS(79), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_identifier,
  [352] = 1,
    ACTIONS(81), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_minus,
  [358] = 2,
    ACTIONS(85), 1,
      sym_minus,
    ACTIONS(83), 2,
      sym_identifier,
      sym__text,
  [366] = 1,
    ACTIONS(87), 3,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
      sym_identifier,
  [372] = 2,
    ACTIONS(89), 1,
      sym__text,
    STATE(26), 1,
      sym_line,
  [379] = 1,
    ACTIONS(91), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [384] = 2,
    ACTIONS(89), 1,
      sym__text,
    STATE(24), 1,
      sym_line,
  [391] = 1,
    ACTIONS(93), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [396] = 1,
    ACTIONS(95), 2,
      ts_builtin_sym_end,
      anon_sym_LBRACK,
  [401] = 1,
    ACTIONS(97), 1,
      sym_identifier,
  [405] = 1,
    ACTIONS(99), 1,
      sym_identifier,
  [409] = 1,
    ACTIONS(101), 1,
      sym_identifier,
  [413] = 1,
    ACTIONS(103), 1,
      ts_builtin_sym_end,
  [417] = 1,
    ACTIONS(105), 1,
      anon_sym_COLON,
  [421] = 1,
    ACTIONS(107), 1,
      anon_sym_RBRACK,
  [425] = 1,
    ACTIONS(109), 1,
      ts_builtin_sym_end,
  [429] = 1,
    ACTIONS(111), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 25,
  [SMALL_STATE(4)] = 50,
  [SMALL_STATE(5)] = 79,
  [SMALL_STATE(6)] = 104,
  [SMALL_STATE(7)] = 132,
  [SMALL_STATE(8)] = 155,
  [SMALL_STATE(9)] = 178,
  [SMALL_STATE(10)] = 198,
  [SMALL_STATE(11)] = 218,
  [SMALL_STATE(12)] = 231,
  [SMALL_STATE(13)] = 240,
  [SMALL_STATE(14)] = 249,
  [SMALL_STATE(15)] = 258,
  [SMALL_STATE(16)] = 267,
  [SMALL_STATE(17)] = 276,
  [SMALL_STATE(18)] = 290,
  [SMALL_STATE(19)] = 304,
  [SMALL_STATE(20)] = 318,
  [SMALL_STATE(21)] = 326,
  [SMALL_STATE(22)] = 340,
  [SMALL_STATE(23)] = 346,
  [SMALL_STATE(24)] = 352,
  [SMALL_STATE(25)] = 358,
  [SMALL_STATE(26)] = 366,
  [SMALL_STATE(27)] = 372,
  [SMALL_STATE(28)] = 379,
  [SMALL_STATE(29)] = 384,
  [SMALL_STATE(30)] = 391,
  [SMALL_STATE(31)] = 396,
  [SMALL_STATE(32)] = 401,
  [SMALL_STATE(33)] = 405,
  [SMALL_STATE(34)] = 409,
  [SMALL_STATE(35)] = 413,
  [SMALL_STATE(36)] = 417,
  [SMALL_STATE(37)] = 421,
  [SMALL_STATE(38)] = 425,
  [SMALL_STATE(39)] = 429,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 2, 0, 26),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(32),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat2, 2, 0, 24),
  [17] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat2, 2, 0, 24), SHIFT_REPEAT(32),
  [20] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat2, 2, 0, 24), SHIFT_REPEAT(33),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1, 0, 6),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_line, 1, 0, 18),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [31] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 2, 0, 17),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 1, 0, 4),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entries_repeat1, 2, 0, 13),
  [39] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entries_repeat1, 2, 0, 13), SHIFT_REPEAT(34),
  [42] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entries, 1, 0, 5),
  [44] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0),
  [46] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(20),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_tag, 2, 0, 23),
  [51] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_label, 2, 0, 22),
  [53] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__meta, 1, 0, 16),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__meta, 1, 0, 15),
  [57] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat2, 1, 0, 14),
  [59] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryList_repeat1, 2, 0, 21),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entryList_repeat1, 2, 0, 21), SHIFT_REPEAT(29),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryObject, 2, 0, 10),
  [66] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryList, 2, 0, 11),
  [70] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 1, 0, 0),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryObject_repeat1, 2, 0, 20),
  [74] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_entryObject_repeat1, 2, 0, 20), SHIFT_REPEAT(36),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryList_repeat1, 1, 0, 8),
  [79] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryObject_repeat1, 1, 0, 7),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_listItem, 2, 0, 19),
  [83] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_header, 3, 0, 0),
  [85] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_header, 3, 0, 0),
  [87] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 3, 0, 25),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [91] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryText, 2, 0, 9),
  [93] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entries_repeat1, 1, 0, 3),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entries_repeat1, 1, 0, 2),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [103] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 2, 0, 12),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_doc, 1, 0, 1),
  [111] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_woml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
