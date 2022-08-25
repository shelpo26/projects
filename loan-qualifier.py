# this determines whether a customer qualifies for a loan

# min salary
min_salary = float(input('Enter the minimum salary: '))

# min years working
min_years = int(input('Enter the minimum number of years: '))

# Get customers annual salary
salary = float(input('Enter you annual salary: '))

# see if customer qualifies
if salary >= min_salary
    # get number of years on current job
    years_on_job = int(input('Enter number of years employed: '))
    if years_on_job >= min_years:
        print('You qualify. \n')
        print('Your salary is: ${:.2f}'. format(salary))
        print('You worked for: ', years_on_job)
    else:
        print('You must be employed for at least', min_years, 'years to qualify.')
