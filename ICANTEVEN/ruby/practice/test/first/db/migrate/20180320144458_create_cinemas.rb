class CreateCinemas < ActiveRecord::Migration[5.1]
  def change
    create_table :cinemas do |t|
      t.string :location
      t.integer :cinema_id

      t.timestamps
    end
  end
end
