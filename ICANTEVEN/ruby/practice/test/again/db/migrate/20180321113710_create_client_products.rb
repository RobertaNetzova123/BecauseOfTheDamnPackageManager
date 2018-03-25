class CreateClientProducts < ActiveRecord::Migration[5.1]
  def change
    create_table :client_products do |t|
      t.integer :product_id
      t.integer :client_id

      t.timestamps
    end
  end
end
