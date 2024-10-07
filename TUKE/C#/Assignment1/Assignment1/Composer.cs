namespace Assignment1
{
    public class Composer
    {
        private string firstName;
        private string lastName;

        public Composer(string firstName, string lastName)
        {
            this.firstName = firstName;
            this.lastName = lastName;
        }

        public string GetName()
        {
            return firstName + " " + lastName;
        }

        public void SetName(string firstName, string lastName)
        {
            bool isOnlyLetters_for_firstName = firstName.All(char.IsLetter);
            bool isOnlyLetters_for_lastName = lastName.All(char.IsLetter);
            bool isFirstNameValid = !string.IsNullOrEmpty(firstName) && char.IsUpper(firstName[0]) && firstName.Skip(1).All(char.IsLower);
            bool isLastNameValid = !string.IsNullOrEmpty(lastName) && char.IsUpper(lastName[0]) && lastName.Skip(1).All(char.IsLower);

            if (isOnlyLetters_for_firstName && isOnlyLetters_for_lastName && isFirstNameValid && isLastNameValid)
            {
                this.firstName = firstName;
                this.lastName = lastName;
            }
            else
            {
                throw new ArgumentException("Names must contain only letters.");
            }
        }
    }
}
