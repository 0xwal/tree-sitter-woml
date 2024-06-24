const newline = /\r?\n/;

module.exports = grammar({
  name: "woml",

  extra: ($) => [/\s/],
  // extra: ($) => [],

  // conflicts: ($) => [[$.text]],
  rules: {
    doc: ($) =>
      seq(
        alias(field("rootText", optional($.text)), $.rootText),
        field("entries", optional($.entries)),
      ),

    entries: ($) =>
      repeat1(
        choice(
          field("entryList", alias($.entryList, $.entry)),
          field("entryObject", alias($.entryObject, $.entry)),
          $.entryText,
        ),
      ),

    entryObject: ($) => seq($.header, repeat1(field("pair", $.pair))),
    pair: ($) => seq(field("key", $.identifier), ":", field("value", $.line)),

    entryText: ($) => seq($.header, alias($.text, $.content)),

    entryList: ($) => seq($.header, repeat1(field("listItem", $.listItem))),
    listItem: ($) => seq($.minus, field("item", alias($.line, $.value))),

    header: ($) => seq("[", $.identifier, "]"),

    text: ($) => seq(alias(repeat1($._text), $.text), repeat($._meta)),

    line: ($) => seq(field("line", alias($._text, $.text)), repeat($._meta)),

    _meta: ($) => choice(field("label", $.label), field("tag", $.tag)),

    label: ($) => seq("@", alias($.identifier, "labelIdentifier")),
    tag: ($) => seq("#", alias($.identifier, "tagIdentifier")),

    identifier: ($) => token(/[a-zA-Z_][\w]*/),

    _text: ($) => token(/[\w\d][\w\d_\'\"\()\[\]\{\}\.\,\?\! -]+/),

    minus: ($) => "-",
  },
});
