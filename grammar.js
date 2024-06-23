const newline = /\r?\n/;

module.exports = grammar({
  name: "token",

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

    entryObject: ($) => seq($.header, repeat1($.pair)),
    pair: ($) => seq(field("key", $.identifier), ":", field("value", $.line)),

    entryText: ($) => seq($.header, alias($.text, $.content)),

    entryList: ($) => seq($.header, repeat1($.listItem)),
    listItem: ($) => seq($.minus, field("item", alias($.line, $.value))),

    header: ($) => seq("[", $.identifier, "]"),

    text: ($) => seq(alias(repeat1($._text), $.text), repeat($._meta)),

    line: ($) => seq(field("line", alias($._text, $.text)), repeat($._meta)),

    _meta: ($) => choice(field("label", $.label), field("tag", $.tag)),

    label: ($) => seq("@", alias($.identifier, "labelIdentifier")),
    tag: ($) => seq("#", alias($.identifier, "tagIdentifier")),

    identifier: ($) => token(/[a-zA-Z][\w]*/),

    _text: ($) => token(/[\w\d][\w\d_\'\"\()\[\]\{\} -]+/),

    minus: ($) => "-",
  },
});
