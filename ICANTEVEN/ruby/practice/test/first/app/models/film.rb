class Film < ApplicationRecord
	has_many:cinemas
	validates :cinema_id, uniqueness: true
	belongs_to:cinema
end
