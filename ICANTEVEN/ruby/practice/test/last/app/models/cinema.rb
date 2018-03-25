class Cinema < ApplicationRecord
	has_many:cinema_films
	has_many:films, through: :cinema_films
end
