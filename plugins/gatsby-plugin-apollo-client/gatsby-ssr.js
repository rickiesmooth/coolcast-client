require(`isomorphic-unfetch`)
require('ws')
const preferDefault = m => (m && m.default) || m
exports.wrapRootElement = preferDefault(require(`./inject-provider`))
