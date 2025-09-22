#!/usr/bin/env ruby
# Print numeric CLI arguments sorted ascending, one per line.

nums = ARGV.filter_map { |s| Integer(s, exception: false) } # ignores non-numbers
nums.sort.each { |n| puts n }
