import React, { useRef } from 'react'
import { useRouter } from 'next/router'
import { Form, Button } from 'react-bootstrap'

const Users = () => {
	const userRef = useRef(null)

	const usernameRef = useRef(null)
	const emailRef = useRef(null)
	const passwordRef = useRef(null)
	const genderRef = useRef(null)

	const router = useRouter()

	const handleAddUserClick = (e) => {
		e.preventDefault() // Prevent default form submission
		const userData = {
			username: usernameRef.current.value,
			email: emailRef.current.value,
			password: passwordRef.current.value,
			gender: genderRef.current.value,
		}

		fetch('https://api-nodejs-y7qorp3gha-ey.a.run.app/api/user/register', {
			method: 'POST',
			headers: {
				'Content-Type': 'application/json',
			},
			body: JSON.stringify(userData),
		})
			.then((response) => response.json())
			.then((data) => {
				console.log('Success:', data)
				router.push(`/users/${userData.username}`)
			})
			.catch((error) => {
				console.error('Error:', error)
			})
	}
	return (
		<div
			style={{
				width: '100%',
				display: 'flex',
				justifyContent: 'center',
			}}
		>
			<div
				style={{
					display: 'flex',
					flexDirection: 'column',
					alignItems: 'center',
					gap: '25px',
					width: '75%',
				}}
			>
				<div style={{ display: 'flex', width: '100%' }}>
					<Form.Control
						size='lg'
						type='text'
						placeholder='Search User...'
						ref={userRef}
					/>
					<Button
						variant='primary'
						size='lg'
						onClick={() => {
							const userValue = userRef.current.value
							router.push(`/users/${userValue}`)
						}}
					>
						Search
					</Button>
				</div>

				<div
					style={{
						width: '100%',
						height: '300px',
						backgroundColor: '#f0f0f0',
						borderRadius: '10px',
						display: 'flex',
						flexDirection: 'column',
						gap: '20px',
						paddingTop: '10px',
					}}
				>
					<Form>
						<Form.Group className='mb-3'>
							<Form.Label>Username</Form.Label>
							<Form.Control
								type='text'
								placeholder='Enter username'
								ref={usernameRef}
							/>
						</Form.Group>
						<Form.Group className='mb-3'>
							<Form.Label>Email</Form.Label>
							<Form.Control
								type='email'
								placeholder='name@example.com'
								ref={emailRef}
							/>
						</Form.Group>
						<Form.Group className='mb-3'>
							<Form.Label>Password</Form.Label>
							<Form.Control
								type='password'
								placeholder='Enter password'
								ref={passwordRef}
							/>
						</Form.Group>
						<Form.Group
							className='mb-3'
							controlId='exampleForm.ControlTextarea1'
						>
							<Form.Label>Gender</Form.Label>
							<Form.Select aria-label='Default select example' ref={genderRef}>
								<option value='male'>Male</option>
								<option value='female'>Female</option>
							</Form.Select>
						</Form.Group>
					</Form>
					<Button onClick={handleAddUserClick}>Add User</Button>
				</div>
			</div>
		</div>
	)
}

export default Users
