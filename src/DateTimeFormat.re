type dateTimeFormat;

[@bs.deriving abstract]
type formatOptions = {
  [@bs.optional]
  weekday: string,
  [@bs.optional]
  day: string,
  [@bs.optional]
  month: string,
};

[@bs.new]
external dateTimeFormat: (string, formatOptions) => dateTimeFormat =
  "Intl.DateTimeFormat";

/* The empty string means "the JS name is the same as the name we're giving the external in BuckleScript-land"
 */
[@bs.send] external format: (dateTimeFormat, Js.Date.t) => string = "";

/**
 * TODO: Figure out how to bind this properly?
 */
let locale: string = [%bs.raw {| navigator.language |}];

let shortWeekdayFormatter =
  dateTimeFormat(locale, formatOptions(~weekday="short", ()));

/**
* The graphQL thingy isn't a string :[
 */
let toStr = (date: Js.Json.t) =>
  date |> Js.Json.decodeString |> Js.Option.getExn;
/**
 * Given a Date string, returns short day name, like Wed/Ons
 */
let shortWeekDay = (date: Js.Json.t) =>
  shortWeekdayFormatter->format(Js.Date.fromString(toStr(date)));

let dayFormatter =
  dateTimeFormat(
    locale,
    formatOptions(~day="2-digit", ~month="2-digit", ()),
  );

let day = (date: Js.Json.t) =>
  dayFormatter->format(Js.Date.fromString(toStr(date)));