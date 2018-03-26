Rails.application.routes.draw do
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html

	root 'products#index'

	resources :products

	get '/products',             to: 'products#index'
	get '/products/new',         to: 'products#new'
	get '/products/:id',         to: 'products#show'
	post '/products',            to: 'products#create'
	delete '/products/:id',      to: 'products#destroy'
		
end
