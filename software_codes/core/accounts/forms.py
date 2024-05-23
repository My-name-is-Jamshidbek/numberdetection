from django import forms
from django.contrib.auth.forms import UserCreationForm
from django.contrib.auth.models import User


class SignUpForm(UserCreationForm):
    fullname = forms.CharField(max_length=255, required=True, help_text='Full name')
    vehicle_number = forms.CharField(max_length=255, required=True, help_text='Vehicle number')
    email = forms.EmailField(max_length=255, required=True, help_text='Email address')
    phone_number = forms.CharField(max_length=255, required=True, help_text='Phone number')

    class Meta:
        model = User
        fields = ('fullname', 'vehicle_number', 'username', 'email', 'phone_number', 'password1', 'password2')


class LoginForm(forms.Form):
    username = forms.CharField(max_length=255, required=True, help_text='Username')
    password = forms.CharField(widget=forms.PasswordInput, required=True, help_text='Password')
