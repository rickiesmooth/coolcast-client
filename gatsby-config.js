module.exports = {
  siteMetadata: {
    title: 'Gatsby Starter Reason',
  },
  plugins: [
    'gatsby-plugin-react-helmet',
    'gatsby-plugin-react-native-web',
    'gatsby-plugin-apollo-client',
    {
      resolve: 'gatsby-plugin-reason',
    },
  ],
}
