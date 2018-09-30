'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.onCreatePage = exports.resolvableExtensions = exports.preprocessSource = exports.onCreateWebpackConfig = undefined;

var _bsbJs = require('bsb-js');

var _fs = require('fs');

var _fs2 = _interopRequireDefault(_fs);

var _utils = require('./utils');

var _path = require('path');

var _path2 = _interopRequireDefault(_path);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var BS_TEST = /\.(bs.js)$/;
var REASON_TEST = /\.(ml|re)$/;

var isCompiledFile = function isCompiledFile(fileName) {
  return BS_TEST.test(fileName);
};
var isReasonFile = function isReasonFile(fileName) {
  return REASON_TEST.test(fileName);
};

var onCreateWebpackConfig = exports.onCreateWebpackConfig = function onCreateWebpackConfig(_ref) {
  var stage = _ref.stage,
      actions = _ref.actions;
  var setWebpackConfig = actions.setWebpackConfig;

  setWebpackConfig({
    module: {
      rules: [{
        test: REASON_TEST,
        use: ['bs-loader']
      }]
    }
  });
};
var jsFilePath = function jsFilePath(buildDir, moduleDir, resourcePath, inSource, bsSuffix) {
  var mlFileName = resourcePath.replace(buildDir, '');
  var jsFileName = mlFileName.replace(REASON_TEST, bsSuffix);

  if (inSource) {
    return _path2.default.join(buildDir, jsFileName);
  }

  return _path2.default.join(buildDir, 'lib', moduleDir, jsFileName);
};

var preprocessSource = exports.preprocessSource = function preprocessSource(_ref2) {
  var filename = _ref2.filename;

  if (!isReasonFile(filename)) {
    return null;
  }
  var moduleDir = 'js';
  var compiledFilePath = jsFilePath(process.cwd(), moduleDir, filename, false, '.bs.js');
  try {
    return (0, _bsbJs.compileFileSync)(moduleDir, compiledFilePath);
  } catch (e) {
    // Don't need to print error message since bsb will already do that
  }
};

var resolvableExtensions = exports.resolvableExtensions = function resolvableExtensions() {
  return ['.ml', '.re'];
};

var onCreatePage = exports.onCreatePage = function onCreatePage(_ref3, _ref4) {
  var page = _ref3.page,
      _ref3$boundActionCrea = _ref3.boundActionCreators,
      createPage = _ref3$boundActionCrea.createPage,
      deletePage = _ref3$boundActionCrea.deletePage;
  var derivePathFromComponentName = _ref4.derivePathFromComponentName;

  return new Promise(function (resolve, reject) {
    var oldPage = Object.assign({}, page);
    var component = page.component,
        path = page.path;


    if (isCompiledFile(component)) {
      // Remove .bs components so we don't have duplicates
      deletePage(oldPage);
    } else if (derivePathFromComponentName && isReasonFile(component) && !path.endsWith('.html')) {
      // Try to grab the name of the component from the ReasonReact
      // component instead of using the file name
      var source = _fs2.default.readFileSync(component, 'utf-8');
      var newPath = (0, _utils.getPathForComponent)(source);
      if (newPath !== undefined) {
        var newPage = Object.assign({}, page, { path: newPath });
        deletePage(oldPage);
        createPage(newPage);
      }
    }

    resolve();
  });
};