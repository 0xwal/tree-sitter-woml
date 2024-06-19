#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 37
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 26
#define ALIAS_COUNT 0
#define TOKEN_COUNT 11
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 10
#define MAX_ALIAS_SEQUENCE_LENGTH 4
#define PRODUCTION_ID_COUNT 17

enum ts_symbol_identifiers {
  anon_sym_EQ = 1,
  anon_sym_LF = 2,
  anon_sym_LBRACK = 3,
  aux_sym__header_token1 = 4,
  anon_sym_RBRACK = 5,
  anon_sym_DASH = 6,
  sym_key = 7,
  aux_sym_text_token1 = 8,
  sym_tag = 9,
  sym_label = 10,
  sym_document = 11,
  sym_entryObject = 12,
  sym_entryList = 13,
  sym_entryText = 14,
  sym_pair = 15,
  sym__header = 16,
  sym__listItem = 17,
  sym_value = 18,
  sym_text = 19,
  sym_meta = 20,
  aux_sym_document_repeat1 = 21,
  aux_sym_entryObject_repeat1 = 22,
  aux_sym_entryList_repeat1 = 23,
  aux_sym_text_repeat1 = 24,
  aux_sym_meta_repeat1 = 25,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_EQ] = "=",
  [anon_sym_LF] = "\n",
  [anon_sym_LBRACK] = "[",
  [aux_sym__header_token1] = "_header_token1",
  [anon_sym_RBRACK] = "]",
  [anon_sym_DASH] = "-",
  [sym_key] = "key",
  [aux_sym_text_token1] = "text_token1",
  [sym_tag] = "tag",
  [sym_label] = "label",
  [sym_document] = "document",
  [sym_entryObject] = "entryObject",
  [sym_entryList] = "entryList",
  [sym_entryText] = "entryText",
  [sym_pair] = "pair",
  [sym__header] = "_header",
  [sym__listItem] = "_listItem",
  [sym_value] = "value",
  [sym_text] = "text",
  [sym_meta] = "meta",
  [aux_sym_document_repeat1] = "document_repeat1",
  [aux_sym_entryObject_repeat1] = "entryObject_repeat1",
  [aux_sym_entryList_repeat1] = "entryList_repeat1",
  [aux_sym_text_repeat1] = "text_repeat1",
  [aux_sym_meta_repeat1] = "meta_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LF] = anon_sym_LF,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [aux_sym__header_token1] = aux_sym__header_token1,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_DASH] = anon_sym_DASH,
  [sym_key] = sym_key,
  [aux_sym_text_token1] = aux_sym_text_token1,
  [sym_tag] = sym_tag,
  [sym_label] = sym_label,
  [sym_document] = sym_document,
  [sym_entryObject] = sym_entryObject,
  [sym_entryList] = sym_entryList,
  [sym_entryText] = sym_entryText,
  [sym_pair] = sym_pair,
  [sym__header] = sym__header,
  [sym__listItem] = sym__listItem,
  [sym_value] = sym_value,
  [sym_text] = sym_text,
  [sym_meta] = sym_meta,
  [aux_sym_document_repeat1] = aux_sym_document_repeat1,
  [aux_sym_entryObject_repeat1] = aux_sym_entryObject_repeat1,
  [aux_sym_entryList_repeat1] = aux_sym_entryList_repeat1,
  [aux_sym_text_repeat1] = aux_sym_text_repeat1,
  [aux_sym_meta_repeat1] = aux_sym_meta_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LF] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__header_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [sym_key] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_text_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_label] = {
    .visible = true,
    .named = true,
  },
  [sym_document] = {
    .visible = true,
    .named = true,
  },
  [sym_entryObject] = {
    .visible = true,
    .named = true,
  },
  [sym_entryList] = {
    .visible = true,
    .named = true,
  },
  [sym_entryText] = {
    .visible = true,
    .named = true,
  },
  [sym_pair] = {
    .visible = true,
    .named = true,
  },
  [sym__header] = {
    .visible = false,
    .named = true,
  },
  [sym__listItem] = {
    .visible = false,
    .named = true,
  },
  [sym_value] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_meta] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_document_repeat1] = {
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
  [aux_sym_meta_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_entryList = 1,
  field_entryObject = 2,
  field_entryText = 3,
  field_itemList = 4,
  field_label = 5,
  field_meta = 6,
  field_pair = 7,
  field_rootText = 8,
  field_tag = 9,
  field_text = 10,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_entryList] = "entryList",
  [field_entryObject] = "entryObject",
  [field_entryText] = "entryText",
  [field_itemList] = "itemList",
  [field_label] = "label",
  [field_meta] = "meta",
  [field_pair] = "pair",
  [field_rootText] = "rootText",
  [field_tag] = "tag",
  [field_text] = "text",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 1},
  [5] = {.index = 4, .length = 3},
  [6] = {.index = 7, .length = 1},
  [7] = {.index = 8, .length = 1},
  [8] = {.index = 9, .length = 1},
  [9] = {.index = 10, .length = 4},
  [10] = {.index = 14, .length = 6},
  [11] = {.index = 20, .length = 1},
  [12] = {.index = 21, .length = 1},
  [13] = {.index = 22, .length = 1},
  [14] = {.index = 23, .length = 2},
  [15] = {.index = 25, .length = 2},
  [16] = {.index = 27, .length = 4},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_entryObject, 0},
  [1] =
    {field_entryList, 0},
  [2] =
    {field_entryText, 0},
  [3] =
    {field_rootText, 0},
  [4] =
    {field_entryList, 0, .inherited = true},
    {field_entryObject, 0, .inherited = true},
    {field_entryText, 0, .inherited = true},
  [7] =
    {field_text, 1},
  [8] =
    {field_pair, 1},
  [9] =
    {field_itemList, 1},
  [10] =
    {field_entryList, 1, .inherited = true},
    {field_entryObject, 1, .inherited = true},
    {field_entryText, 1, .inherited = true},
    {field_rootText, 0},
  [14] =
    {field_entryList, 0, .inherited = true},
    {field_entryList, 1, .inherited = true},
    {field_entryObject, 0, .inherited = true},
    {field_entryObject, 1, .inherited = true},
    {field_entryText, 0, .inherited = true},
    {field_entryText, 1, .inherited = true},
  [20] =
    {field_text, 0},
  [21] =
    {field_tag, 0},
  [22] =
    {field_label, 0},
  [23] =
    {field_meta, 1},
    {field_text, 0},
  [25] =
    {field_label, 0, .inherited = true},
    {field_tag, 0, .inherited = true},
  [27] =
    {field_label, 0, .inherited = true},
    {field_label, 1, .inherited = true},
    {field_tag, 0, .inherited = true},
    {field_tag, 1, .inherited = true},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
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
  [13] = 12,
  [14] = 14,
  [15] = 11,
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(5);
      ADVANCE_MAP(
        '\n', 7,
        '#', 2,
        '-', 11,
        '=', 6,
        '@', 3,
        '[', 8,
        ']', 10,
        '"', 13,
        '\'', 13,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(0);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(7);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 2:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 3:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 4:
      if (eof) ADVANCE(5);
      if (lookahead == '\n') ADVANCE(7);
      if (lookahead == '#') ADVANCE(2);
      if (lookahead == '@') ADVANCE(3);
      if (lookahead == '[') ADVANCE(8);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(4);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_LF);
      if (lookahead == '\n') ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(aux_sym__header_token1);
      if (lookahead == '-' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(9);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(sym_key);
      if (lookahead == '"' ||
          lookahead == '\'') ADVANCE(13);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym_text_token1);
      if (lookahead == '"' ||
          lookahead == '\'' ||
          ('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(13);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(sym_tag);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(14);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_label);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 4},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 4},
  [12] = {.lex_state = 4},
  [13] = {.lex_state = 4},
  [14] = {.lex_state = 4},
  [15] = {.lex_state = 4},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 4},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LF] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [sym_key] = ACTIONS(1),
    [aux_sym_text_token1] = ACTIONS(1),
    [sym_tag] = ACTIONS(1),
    [sym_label] = ACTIONS(1),
  },
  [1] = {
    [sym_document] = STATE(30),
    [sym_entryObject] = STATE(24),
    [sym_entryList] = STATE(28),
    [sym_entryText] = STATE(27),
    [sym__header] = STATE(2),
    [sym_text] = STATE(4),
    [aux_sym_document_repeat1] = STATE(5),
    [aux_sym_text_repeat1] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(5),
    [anon_sym_LF] = ACTIONS(3),
    [anon_sym_LBRACK] = ACTIONS(7),
    [aux_sym_text_token1] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(9), 1,
      aux_sym_text_token1,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(13), 1,
      sym_key,
    STATE(13), 1,
      aux_sym_text_repeat1,
    STATE(26), 1,
      sym_text,
    STATE(8), 2,
      sym_pair,
      aux_sym_entryObject_repeat1,
    STATE(9), 2,
      sym__listItem,
      aux_sym_entryList_repeat1,
  [27] = 8,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(15), 1,
      ts_builtin_sym_end,
    ACTIONS(17), 1,
      anon_sym_LBRACK,
    STATE(2), 1,
      sym__header,
    STATE(3), 1,
      aux_sym_document_repeat1,
    STATE(24), 1,
      sym_entryObject,
    STATE(27), 1,
      sym_entryText,
    STATE(28), 1,
      sym_entryList,
  [52] = 8,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(20), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym__header,
    STATE(6), 1,
      aux_sym_document_repeat1,
    STATE(24), 1,
      sym_entryObject,
    STATE(27), 1,
      sym_entryText,
    STATE(28), 1,
      sym_entryList,
  [77] = 8,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(22), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym__header,
    STATE(3), 1,
      aux_sym_document_repeat1,
    STATE(24), 1,
      sym_entryObject,
    STATE(27), 1,
      sym_entryText,
    STATE(28), 1,
      sym_entryList,
  [102] = 8,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(7), 1,
      anon_sym_LBRACK,
    ACTIONS(24), 1,
      ts_builtin_sym_end,
    STATE(2), 1,
      sym__header,
    STATE(3), 1,
      aux_sym_document_repeat1,
    STATE(24), 1,
      sym_entryObject,
    STATE(27), 1,
      sym_entryText,
    STATE(28), 1,
      sym_entryList,
  [127] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(26), 1,
      ts_builtin_sym_end,
    ACTIONS(28), 1,
      anon_sym_LBRACK,
    ACTIONS(30), 1,
      sym_key,
    STATE(7), 2,
      sym_pair,
      aux_sym_entryObject_repeat1,
  [144] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(13), 1,
      sym_key,
    ACTIONS(33), 1,
      ts_builtin_sym_end,
    ACTIONS(35), 1,
      anon_sym_LBRACK,
    STATE(7), 2,
      sym_pair,
      aux_sym_entryObject_repeat1,
  [161] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(11), 1,
      anon_sym_DASH,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      anon_sym_LBRACK,
    STATE(10), 2,
      sym__listItem,
      aux_sym_entryList_repeat1,
  [178] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(41), 1,
      ts_builtin_sym_end,
    ACTIONS(43), 1,
      anon_sym_LBRACK,
    ACTIONS(45), 1,
      anon_sym_DASH,
    STATE(10), 2,
      sym__listItem,
      aux_sym_entryList_repeat1,
  [195] = 4,
    ACTIONS(48), 1,
      anon_sym_LF,
    ACTIONS(50), 1,
      aux_sym_text_token1,
    STATE(11), 1,
      aux_sym_text_repeat1,
    ACTIONS(53), 2,
      sym_tag,
      sym_label,
  [209] = 4,
    ACTIONS(55), 1,
      anon_sym_LF,
    ACTIONS(57), 1,
      aux_sym_text_token1,
    STATE(11), 1,
      aux_sym_text_repeat1,
    ACTIONS(59), 2,
      sym_tag,
      sym_label,
  [223] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(55), 1,
      ts_builtin_sym_end,
    ACTIONS(59), 1,
      anon_sym_LBRACK,
    ACTIONS(61), 1,
      aux_sym_text_token1,
    STATE(15), 1,
      aux_sym_text_repeat1,
  [239] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(63), 1,
      aux_sym_text_token1,
    STATE(12), 1,
      aux_sym_text_repeat1,
    STATE(16), 1,
      sym_text,
    STATE(36), 1,
      sym_value,
  [255] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(48), 1,
      ts_builtin_sym_end,
    ACTIONS(53), 1,
      anon_sym_LBRACK,
    ACTIONS(65), 1,
      aux_sym_text_token1,
    STATE(15), 1,
      aux_sym_text_repeat1,
  [271] = 5,
    ACTIONS(68), 1,
      anon_sym_LF,
    ACTIONS(70), 1,
      sym_tag,
    ACTIONS(72), 1,
      sym_label,
    STATE(20), 1,
      aux_sym_meta_repeat1,
    STATE(34), 1,
      sym_meta,
  [287] = 5,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(63), 1,
      aux_sym_text_token1,
    STATE(12), 1,
      aux_sym_text_repeat1,
    STATE(16), 1,
      sym_text,
    STATE(35), 1,
      sym_value,
  [303] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(74), 1,
      ts_builtin_sym_end,
    ACTIONS(76), 2,
      anon_sym_LBRACK,
      sym_key,
  [314] = 4,
    ACTIONS(78), 1,
      anon_sym_LF,
    ACTIONS(80), 1,
      sym_tag,
    ACTIONS(83), 1,
      sym_label,
    STATE(19), 1,
      aux_sym_meta_repeat1,
  [327] = 4,
    ACTIONS(70), 1,
      sym_tag,
    ACTIONS(72), 1,
      sym_label,
    ACTIONS(86), 1,
      anon_sym_LF,
    STATE(19), 1,
      aux_sym_meta_repeat1,
  [340] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(88), 1,
      ts_builtin_sym_end,
    ACTIONS(90), 2,
      anon_sym_LBRACK,
      anon_sym_DASH,
  [351] = 2,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(92), 3,
      anon_sym_DASH,
      sym_key,
      aux_sym_text_token1,
  [360] = 2,
    ACTIONS(94), 1,
      anon_sym_LF,
    ACTIONS(96), 2,
      sym_tag,
      sym_label,
  [368] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(98), 1,
      ts_builtin_sym_end,
    ACTIONS(100), 1,
      anon_sym_LBRACK,
  [378] = 2,
    ACTIONS(102), 1,
      anon_sym_LF,
    ACTIONS(104), 2,
      sym_tag,
      sym_label,
  [386] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(106), 1,
      ts_builtin_sym_end,
    ACTIONS(108), 1,
      anon_sym_LBRACK,
  [396] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(110), 1,
      ts_builtin_sym_end,
    ACTIONS(112), 1,
      anon_sym_LBRACK,
  [406] = 3,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(114), 1,
      ts_builtin_sym_end,
    ACTIONS(116), 1,
      anon_sym_LBRACK,
  [416] = 2,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(118), 1,
      anon_sym_EQ,
  [423] = 2,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(120), 1,
      ts_builtin_sym_end,
  [430] = 2,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(122), 1,
      aux_sym__header_token1,
  [437] = 2,
    ACTIONS(3), 1,
      anon_sym_LF,
    ACTIONS(124), 1,
      anon_sym_RBRACK,
  [444] = 1,
    ACTIONS(126), 1,
      anon_sym_LF,
  [448] = 1,
    ACTIONS(128), 1,
      anon_sym_LF,
  [452] = 1,
    ACTIONS(130), 1,
      anon_sym_LF,
  [456] = 1,
    ACTIONS(132), 1,
      anon_sym_LF,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 52,
  [SMALL_STATE(5)] = 77,
  [SMALL_STATE(6)] = 102,
  [SMALL_STATE(7)] = 127,
  [SMALL_STATE(8)] = 144,
  [SMALL_STATE(9)] = 161,
  [SMALL_STATE(10)] = 178,
  [SMALL_STATE(11)] = 195,
  [SMALL_STATE(12)] = 209,
  [SMALL_STATE(13)] = 223,
  [SMALL_STATE(14)] = 239,
  [SMALL_STATE(15)] = 255,
  [SMALL_STATE(16)] = 271,
  [SMALL_STATE(17)] = 287,
  [SMALL_STATE(18)] = 303,
  [SMALL_STATE(19)] = 314,
  [SMALL_STATE(20)] = 327,
  [SMALL_STATE(21)] = 340,
  [SMALL_STATE(22)] = 351,
  [SMALL_STATE(23)] = 360,
  [SMALL_STATE(24)] = 368,
  [SMALL_STATE(25)] = 378,
  [SMALL_STATE(26)] = 386,
  [SMALL_STATE(27)] = 396,
  [SMALL_STATE(28)] = 406,
  [SMALL_STATE(29)] = 416,
  [SMALL_STATE(30)] = 423,
  [SMALL_STATE(31)] = 430,
  [SMALL_STATE(32)] = 437,
  [SMALL_STATE(33)] = 444,
  [SMALL_STATE(34)] = 448,
  [SMALL_STATE(35)] = 452,
  [SMALL_STATE(36)] = 456,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 0, 0, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [15] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 2, 0, 10),
  [17] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 2, 0, 10), SHIFT_REPEAT(31),
  [20] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 4),
  [22] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 1, 0, 5),
  [24] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_document, 2, 0, 9),
  [26] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryObject_repeat1, 2, 0, 0),
  [28] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_entryObject_repeat1, 2, 0, 0),
  [30] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entryObject_repeat1, 2, 0, 0), SHIFT_REPEAT(29),
  [33] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryObject, 2, 0, 7),
  [35] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entryObject, 2, 0, 7),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryList, 2, 0, 8),
  [39] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entryList, 2, 0, 8),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_entryList_repeat1, 2, 0, 0),
  [43] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_entryList_repeat1, 2, 0, 0),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_entryList_repeat1, 2, 0, 0), SHIFT_REPEAT(14),
  [48] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(11),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0),
  [55] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_text, 1, 0, 0),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_text, 1, 0, 0),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [65] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_text_repeat1, 2, 0, 0), SHIFT_REPEAT(15),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 1, 0, 11),
  [70] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [72] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [74] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pair, 4, 0, 0),
  [76] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pair, 4, 0, 0),
  [78] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_meta_repeat1, 2, 0, 16),
  [80] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_meta_repeat1, 2, 0, 16), SHIFT_REPEAT(23),
  [83] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_meta_repeat1, 2, 0, 16), SHIFT_REPEAT(25),
  [86] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_meta, 1, 0, 15),
  [88] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__listItem, 3, 0, 0),
  [90] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__listItem, 3, 0, 0),
  [92] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__header, 4, 0, 0),
  [94] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_meta_repeat1, 1, 0, 12),
  [96] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_meta_repeat1, 1, 0, 12),
  [98] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1, 0, 1),
  [100] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 1, 0, 1),
  [102] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_meta_repeat1, 1, 0, 13),
  [104] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_meta_repeat1, 1, 0, 13),
  [106] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_entryText, 2, 0, 6),
  [108] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_entryText, 2, 0, 6),
  [110] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1, 0, 3),
  [112] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 1, 0, 3),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_document_repeat1, 1, 0, 2),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_document_repeat1, 1, 0, 2),
  [118] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [120] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [124] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [126] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_value, 2, 0, 14),
  [130] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [132] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
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
