type dateTimeFormat;

[@bs.deriving abstract]
type formatOptions = {weekday: string};

[@bs.new]
external dateTimeFormat: (string, formatOptions) => dateTimeFormat =
  "Intl.DateTimeFormat";

[@bs.send] external format: (dateTimeFormat, Js.Date.t) => string = "format";

let now = Js.Date.now()->Js.Date.fromFloat;

let weekdayFormatter =
  dateTimeFormat("en-US", formatOptions(~weekday="short"));

let weekDay = () => weekdayFormatter->format(now);

Js.log(
  dateTimeFormat("en-US", formatOptions(~weekday="short"))->(format(now)),
);