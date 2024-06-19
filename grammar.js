const newline = /\r?\n/;

module.exports = grammar({
  name: "token",

  // extra: ($) => ["\n", "\r", /\s/],
  // extra: ($) => [],

  conflicts: ($) => [[$.line]],
  rules: {
    doc: ($) => seq(field("rootText", optional($.multiline)), $.entries),
    entries: ($) => repeat1($._entry),

    _entry: ($) =>
      seq(choice($.entryObject, $.entryList, $.entryText), newline),

    entryObject: ($) => seq($.header, repeat1($.pair)),
    entryList: ($) => seq($.header, repeat1($.listItem)),
    entryText: ($) => seq($.header, $.multiline),

    pair: ($) =>
      seq(field("key", $.key), "=", field("value", $.paragraph), newline),

    key: ($) => $._word,

    listItem: ($) => seq("-", $.paragraph, newline),

    header: ($) => seq("[", $._word, "]", newline),

    multiline: ($) => prec(1, repeat1(seq($.paragraph, newline))),

    paragraph: ($) => seq($.line, repeat(seq(" ", $._meta))),

    line: ($) => seq($._word, repeat(seq(" ", $._word))),

    _meta: ($) => choice($.tag, $.label),

    label: ($) => seq("@", alias($._word, "label")),
    tag: ($) => seq("#", alias($._word, "tag")),

    _word: ($) => token(/[a-zA-Z0-9_]+/),

    _LETTER: ($) => token(/[a-z]/),
    _DIGIT: ($) => token(/[0-9]/),
  },
});
