var plugin = require('./index');
var base = require('@jupyter-widgets/base');

module.exports = {
  id: 'open3d',
  requires: [base.IJupyterWidgetRegistry],
  activate: function(app, widgets) {
      widgets.registerWidget({
          name: 'open3d',
          version: plugin.version,
          exports: plugin
      });
  },
  autoStart: true
};

