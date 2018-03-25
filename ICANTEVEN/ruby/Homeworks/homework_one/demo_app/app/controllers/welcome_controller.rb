class WelcomeController < ApplicationController
require 'csv'

  def getfile
	name = File.read('params[:file]')
	csv = CSV.parse(name, :headers => true)
	csv.each do |row|
	Moulding.create!(row.to_hash)
	end
	
  end
end
