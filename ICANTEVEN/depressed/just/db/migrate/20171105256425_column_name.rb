class ColumnName < ActiveRecord::Migration[5.1]
  def change
    change_column :messages, :text, :text
    rename_column :messages, :text, :content
  end
end
