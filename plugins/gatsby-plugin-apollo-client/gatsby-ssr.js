require(`isomorphic-unfetch`)
// require('ws')
import * as React from 'react'

import { ApolloClient } from 'apollo-client'
import { createHttpLink } from 'apollo-link-http'
import { InMemoryCache } from 'apollo-cache-inmemory'
import { ApolloProvider } from 'react-apollo'

const apolloClient = new ApolloClient({
    ssrMode: true,
    link: createHttpLink({
        uri: 'https://coolcast-api.now.sh',
        credentials: 'same-origin',
    }),
    cache: new InMemoryCache(),
})

export const wrapRootElement = ({ element }) => (
    <ApolloProvider client={apolloClient}>{element}</ApolloProvider>
)
