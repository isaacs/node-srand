try {
  module.exports = require("./build/Release/srand.node")
} catch (e) {
  module.exports = require("./build/default/srand.node")
}
