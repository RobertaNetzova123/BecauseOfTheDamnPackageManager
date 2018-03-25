class Film < ApplicationRecord
	has_many:cinema_films
	has_many:cinemas, through: :cinema_films
	validates :name, uniqueness: true
end
