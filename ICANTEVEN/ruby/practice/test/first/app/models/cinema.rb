class Cinema < ApplicationRecord
	has_many:films
	validates :name, uniqueness: true
	belongs_to:film
end
