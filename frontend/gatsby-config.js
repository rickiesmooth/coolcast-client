module.exports = {
  siteMetadata: {
    title: "Gatsby ReasonML Starter",
    author: "Rick Smit"
  },
  plugins: [
    "gatsby-plugin-react-helmet",
    "gatsby-plugin-react-native-web",
    {
      resolve: `gatsby-source-filesystem`,
      options: {
        name: `pages`,
        path: `${__dirname}/src/pages`
      }
    },
    "gatsby-transformer-remark"
  ]
};
