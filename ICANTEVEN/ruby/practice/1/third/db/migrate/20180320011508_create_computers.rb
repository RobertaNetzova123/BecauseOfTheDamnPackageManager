class CreateComputers < ActiveRecord::Migration[5.1]
  def change
    create_table :computers do |t|
      t.string :color
      t.string :brand
      t.string :processor
      t.integer :room_id

      t.timestamps
    end
  end
end
