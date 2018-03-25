class Cinema < ApplicationRecord
	has_many:cinema_films
	has_many:films, through: :cinema_films
	validates :cinema_id, uniqueness: true 
end
