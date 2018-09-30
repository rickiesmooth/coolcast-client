'use strict';

exports.onCreateBabelConfig = function (_ref) {
  var actions = _ref.actions;

  actions.setBabelPlugin({
    name: 'babel-plugin-react-native-web'
  });
};

exports.onCreateWebpackConfig = function (_ref2) {
  var actions = _ref2.actions;

  actions.setWebpackConfig({
    resolve: {
      alias: {
        'react-native': 'react-native-web'
      }
    }
  });
};