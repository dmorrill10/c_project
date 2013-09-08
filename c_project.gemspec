# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'c_project/version'

Gem::Specification.new do |spec|
  spec.name          = "c_project"
  spec.version       = CProject::VERSION
  spec.authors       = ["Dustin Morrill"]
  spec.email         = ["morrill@ualberta.ca"]
  spec.description   = %q{Simple C project generator}
  spec.summary       = %q{Simple C project generator}
  spec.homepage      = "https://github.com/dmorrill10/c_project"
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]

  spec.add_dependency 'thor', '~> 0.18.1'

  spec.add_development_dependency "bundler", "~> 1.3"
  spec.add_development_dependency "rake"
end
