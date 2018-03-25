Rails.application.routes.draw do
  resources :subjects
  resources :teachers
get '/B_18_Mihaela_Gadzhalovasubjects/', to: 'teachers#index'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
