import React from 'react'
import "isomorphic-fetch"

import { ApolloProvider } from 'react-apollo'
import { client } from './src/Apollo.bs.js'

export const wrapRootElement = ({ element }) => (
  <ApolloProvider client={client}>{element}</ApolloProvider>
)