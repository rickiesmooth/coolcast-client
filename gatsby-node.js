const path = require("path")

exports.onCreatePage = async ({ page, actions }) => {
    const { createPage } = actions

    if (page.path.match(/^\/messages/)) {
        page.matchPath = "/messages/*"
        createPage({
            path: "/messages/:id",
            component: path.resolve("./src/pages/MessagePage.bs.js")
        })
    }
}