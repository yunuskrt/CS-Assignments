import React from 'react'
import { Button } from 'react-bootstrap'

const index = () => {
	return (
		<div
			style={{
				width: '100%',
				display: 'flex',
				flexDirection: 'column',
				justifyContent: 'center',
				alignItems: 'center',
				height: '70vh',
				letterSpacing: '2px',
			}}
		>
			<h1 style={{ fontWeight: 'bold' }}>Instagram Clone Web App</h1>
			<p>
				This is a very simple front-end web application designed for CS 436
				Cloud Computing course.
			</p>
			<p>Navigate to Users page in order to test the application.</p>
			<Button as='a' href='/users'>
				Visit user page
			</Button>
		</div>
	)
}

export default index
