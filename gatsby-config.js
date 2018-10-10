module.exports = {
  siteMetadata: {
    title: 'Coolcast',
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
