class SumsController < ApplicationController
require 'csv'
  def sums
	sum = Hash.new(0.0)
	name = File.read('params[:file]')
	csv = CSV.parse(name, :headers => true)
	csv.each do |row|
	sum[row[0]] += row[1]	
	end
	
  end
end
