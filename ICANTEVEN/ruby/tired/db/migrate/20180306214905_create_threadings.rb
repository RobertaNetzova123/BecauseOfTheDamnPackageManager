class CreateThreadings < ActiveRecord::Migration[5.1]
  def change
    create_table :threadings do |t|
      t.integer :id => false
      t.integer :value

      t.timestamps
    end
  end
end
