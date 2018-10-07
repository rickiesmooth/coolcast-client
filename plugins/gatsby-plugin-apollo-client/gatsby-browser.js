const React = require(`react`)
const { ApolloProvider } = require('react-apollo')
const { instance } = require('../../src/components/Client')

exports.wrapRootElement = ({ element }) => (
  <ApolloProvider client={instance}>{element}</ApolloProvider>
)
