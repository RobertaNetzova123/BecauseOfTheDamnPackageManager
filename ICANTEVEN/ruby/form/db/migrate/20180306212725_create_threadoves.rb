class CreateThreadoves < ActiveRecord::Migration[5.1]
  def change
    create_table :threadoves do |t|
      t.integer :id => false
      t.integer :value

      t.timestamps
    end
  end
end
