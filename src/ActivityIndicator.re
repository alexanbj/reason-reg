module Styles = {
  open Css;

  let outer =
    style([
      display(flexBox),
      alignItems(center),
      justifyContent(center),
    ]);

  let spin =
    keyframes([
      (0, [transform(rotate(deg(0)))]),
      (100, [transform(rotate(deg(360)))]),
    ]);

  let inner =
    style([
      display(flexBox),
      height(px(36)),
      width(px(36)),
      animation(
        ~duration=750,
        ~timingFunction=linear,
        ~iterationCount=infinite,
        spin,
      ),
    ]);
};

let component = ReasonReact.statelessComponent("ActivityIndicator");

let make = _children => {
  ...component,
  render: _self =>
    <div
      className=Styles.outer
      role="progressbar"
      ariaValuemax=1.
      ariaValuemin=0.>
      <div className=Styles.inner>
        <svg height="100%" viewBox="0 0 32 32" width="100%">
          <circle
            cx="16"
            cy="16"
            fill="none"
            r="14"
            strokeWidth="4"
            stroke="red"
            opacity="0.2"
          />
          <circle
            cx="16"
            cy="16"
            fill="none"
            r="14"
            strokeWidth="4"
            stroke="red"
            strokeDasharray="80"
            strokeDashoffset="60"
          />
        </svg>
      </div>
    </div>,
};