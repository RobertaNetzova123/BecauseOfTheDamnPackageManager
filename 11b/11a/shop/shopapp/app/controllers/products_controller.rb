class ProductsController < ApplicationController

	before_action :find_product, only: [:show]
	
	def index
		@products = Product.all
	end
	
	def show
	end

	def new
		@product = Product.new
	end

	def create
		@product = Product.new(product_params)
		
		if @product_save
			redirect_to @product, notice: "New product created!"
		else
			render 'new'		
		end
	end

	def destroy
		@product.destroy
		redirect_to root_path, notice: "SEEK AND DESTROOOOOY"
	end

private
	
	def product_params
		params.require(:product).permit(:title, :content, :category_id)
	end

	def find_product
		@product = Product.find(params[:id]) 
	end

end
