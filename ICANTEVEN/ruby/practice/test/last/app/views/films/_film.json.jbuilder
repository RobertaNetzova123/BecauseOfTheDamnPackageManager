json.extract! film, :id, :name, :created_at, :updated_at
json.url film_url(film, format: :json)
