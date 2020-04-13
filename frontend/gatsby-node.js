const path = require("path");

exports.onCreatePage = async ({ page, actions }) => {
  const { createPage } = actions;

  if (page.path.match(/^\/podcast/)) {
    page.matchPath = "/podcast/*";
    createPage({
      path: "/podcast/:id",
      component: path.resolve("./src/pages/podcast.js")
    });
  }
};
