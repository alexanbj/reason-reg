const HtmlWebpackPlugin = require('html-webpack-plugin');
const path = require('path');

const outputDir = path.join(__dirname, 'build/');

const isProd = process.env.NODE_ENV === 'production';

module.exports = {
  entry: './src/Index.bs.js',
  mode: isProd ? 'production' : 'development',
  devServer: {
    //hot: true,
    contentBase: path.join(__dirname, 'public'),
    port: 3000,
    historyApiFallback: true
    //disableHostCheck: true,
  },
  output: {
    path: outputDir,
    publicPath: '/',
    filename: isProd ? '[name].[chunkhash].js' : '[name].js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: path.join(__dirname, 'src', 'index.html')
    })
  ]
};
