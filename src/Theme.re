open Css;

let textColor = rgb(44, 62, 80);
let primaryColor = purple;
let secondaryColor = rgb(231, 4, 15);
let shadedColor = rgb(204, 204, 204);

/* Global styles / CSS reset */
global(
  "html",
  [
    boxSizing(borderBox),
    unsafe("WebkitFontSmoothing", "antialiased"),
    unsafe("MozOsxFontSmoothing", "grayscale"),
  ],
);

global("*, *::before, *::after", [unsafe("boxSizing", "inherit")]);

global(
  "body",
  [
    backgroundColor(white),
    margin(zero),
    color(textColor),
    fontFamily(
      "'-apple-system', 'BlinkMacSystemFont', 'Segoe UI', 'Roboto', 'Helvetica Neue', 'Arial', 'sans-serif', 'Apple Color Emoji', 'Segoe UI Emoji', 'Segoe UI Symbol'",
    ),
  ],
);

/* Sticky footer by flexing the main element */
global(
  "#root",
  [
    minHeight(vh(100.)),
    display(flexBox),
    flexDirection(column),
  ],
);

global(
  "main",
  [
    flex(1),
  ],
);