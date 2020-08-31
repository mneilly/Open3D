// Note: This file contains example code from official documentation:
// https://github.com/jupyter-widgets/widget-cookiecutter

// Entry point for the notebook bundle containing custom model definitions.
//
// Setup notebook base URL
//
// Some static assets may be required by the custom widget javascript. The base
// url for the notebook is not known at build time and is therefore computed
// dynamically.
__webpack_public_path__ = "/nbextensions/open3d/";

// Export widget models and views, and the npm package version number.
module.exports = require("./j_visualizer");
module.exports["version"] = require("../package.json").version;