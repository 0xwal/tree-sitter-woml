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
      repeat1(field("entry", choice($.entryList, $.entryObject, $.entryText))),

    entryObject: ($) =>
      seq(field("header", $.header), repeat1(field("pair", $.pair))),
    pair: ($) => seq(field("key", $.identifier), ":", field("value", $.line)),

    entryText: ($) =>
      seq(
        field("header", $.header),
        field("content", alias($.text, $.content)),
      ),

    entryList: ($) =>
      seq(field("header", $.header), repeat1(field("listItem", $.listItem))),
    listItem: ($) => seq($.minus, field("item", alias($.line, $.value))),

    header: ($) => seq("[", field("identifier", $.identifier), "]"),

    text: ($) =>
      seq(field("text", alias(repeat1($._text), $.text)), repeat($._meta)),

    line: ($) => seq(field("line", alias($._text, $.text)), repeat($._meta)),

    _meta: ($) => choice(field("label", $.label), field("tag", $.tag)),

    label: ($) => seq("@", alias($.identifier, "labelIdentifier")),
    tag: ($) => seq("#", alias($.identifier, "tagIdentifier")),

    identifier: ($) => token(/[a-zA-Z_][\w]*/),

    _text: ($) => token(/[\w\d][\w\d_\'\"\()\[\]\{\}\.\,\?\! -]+/),

    minus: ($) => "-",
  },
});
