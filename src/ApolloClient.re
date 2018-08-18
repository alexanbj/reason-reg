/* Create an InMemoryCache */
let inMemoryCache = ApolloInMemoryCache.createInMemoryCache();

/* Create an HTTP Link */
let httpLink =
  ApolloLinks.createHttpLink(~uri="http://localhost:4000/graphql", ());

/* Bearer vs not Bearer??*/
let contextHandler = () => {
  let token = Effects.getTokenFromStorage();
  {
    "headers": {
      "authorization": {j| $token|j},
    },
  };
};
let authLink = ApolloLinks.createContextLink(contextHandler);

let instance =
  ReasonApollo.createApolloClient(
    ~link=ApolloLinks.from([|authLink, httpLink|]),
    ~cache=inMemoryCache,
    (),
  );