json.extract! client_product, :id, :product_id, :client_id, :created_at, :updated_at
json.url client_product_url(client_product, format: :json)
