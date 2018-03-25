Rails.application.routes.draw do
  resources :schools
  resources :students

	get '/B_18_Mihaela_Gadzhalovaschools/', to: 'schools#index'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
