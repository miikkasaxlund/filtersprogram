const gulp = require('gulp')
var exec = require('child_process').exec

const paths = {
  exec: {
    src: "src/*.c",
  }
}

function build(cb) {
  exec('build', function (err, stdout, stderr) {
    console.log(stdout)
    console.log(stderr)
    cb(err)
  })
}

function test(cb) {
  exec('test', function (err, stdout, stderr) {
    console.log(stdout)
    console.log(stderr)
    cb(err)
  })
}

function watch () {
  gulp.watch(paths.exec.src, build)
}

exports.default = watch
exports.build = build
exports.test = test
exports.watch = watch
