let saveTokenToStorage = value =>
  Dom.Storage.(localStorage |> setItem("jwt", value));

/**
 * Get the authentication token from localstorage
 */
let getTokenFromStorage = () =>
  Dom.Storage.(localStorage |> getItem("jwt"));

let removeTokenFromStorage = () =>
  Dom.Storage.(localStorage |> removeItem("jwt"));